#include<iostream>
#include<fstream>

using namespace std;

class SparseMatrix;

class MatrixTerm{
 friend class SparseMatrix;

public:
 int row, col, value;
};

class SparseMatrix{

public:
 int rows, cols, terms, capacity;
 MatrixTerm *smArray;
 SparseMatrix(int r, int c, int t) :rows(r), cols(c), terms(t) {
  if (terms > 0)
   capacity = terms;
  else
   capacity = 1;
  smArray = new MatrixTerm[capacity];
 }
 SparseMatrix FastTranspose();
 SparseMatrix Add(SparseMatrix b);
 SparseMatrix Multiply(SparseMatrix b);
 void StoreMatrix(int d, int i, int j, int v);
 void StoreSum(const int sum, const int r, const int c);
 void ChangeSize1D(const int newSize);

};
void SparseMatrix::StoreMatrix(int idx, int i, int j, int v)
{
 smArray[idx].row = i;
 smArray[idx].col = j;
 smArray[idx].value = v;

}
SparseMatrix SparseMatrix::FastTranspose()
{
 SparseMatrix b(cols, rows, terms);
 if (terms > 0)
 {
  int *rowSize = new int[cols];
  int *rowStart = new int[cols];

  fill(rowSize, rowSize + cols, 0);
  for (int i = 0; i < terms; i++) rowSize[smArray[i].col]++;

  rowStart[0] = 0;
  for (int i = 1; i < cols; i++) rowStart[i] = rowStart[i - 1] + rowSize[i - 1];

  for (int i = 0; i < terms; i++)
  {
   int j = rowStart[smArray[i].col];
   b.smArray[j].row = smArray[i].col;
   b.smArray[j].col = smArray[i].row;
   b.smArray[j].value = smArray[i].value;
   rowStart[smArray[i].col]++;
  }
  delete[] rowSize;
  delete[] rowStart;
 }
 return b;
}

void SparseMatrix::StoreSum(const int sum, const int r, const int c)
{
 if (sum != 0){
  if (terms == capacity)
   ChangeSize1D(2 * capacity);
  smArray[terms].row = r;
  smArray[terms].col = c;
  smArray[terms++].value = sum;
 }
}
void SparseMatrix::ChangeSize1D(const int newSize)
{
 if (newSize < terms) throw"New size must be>=number of terms";
 MatrixTerm *temp = new MatrixTerm[newSize];
 copy(smArray, smArray + terms, temp);
 delete[]smArray;
 smArray = temp;
 capacity = newSize;
}

SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{
 if (cols != b.rows) throw "Incompatible matrices";
 SparseMatrix bXpose = b.FastTranspose();
 SparseMatrix d(rows, b.cols, 0);
 int currRowIndex = 0;
 int currRowBegin = 0;
 int currRowA = smArray[0].row;

 if (terms == capacity) ChangeSize1D(terms + 1);
 bXpose.ChangeSize1D(bXpose.terms + 1);
 smArray[terms].row = rows;
 bXpose.smArray[b.terms].row = b.cols;
 bXpose.smArray[b.terms].col = -1;
 int sum = 0;
 while (currRowIndex < terms)
 {
  int currColB = bXpose.smArray[0].row;
  int currColIndex = 0;
  while (currColIndex <= b.terms)
  {
   if (smArray[currRowIndex].row != currRowA)
   {
    d.StoreSum(sum, currRowA, currColB);
    sum = 0;
    currRowIndex = currRowBegin;
    while (bXpose.smArray[currColIndex].row == currColB)
     currColIndex++;
    currColB = bXpose.smArray[currColIndex].row;
   }
   else if (bXpose.smArray[currColIndex].row != currColB)
   {
    d.StoreSum(sum, currRowA, currColB);
    sum = 0;
    currRowIndex = currRowBegin;
    currColB = bXpose.smArray[currColIndex].row;
   }
   else
    if (smArray[currRowIndex].col <
     bXpose.smArray[currColIndex].col)
     currRowIndex++;
    else if (smArray[currRowIndex].col ==
     bXpose.smArray[currColIndex].col)
     sum += smArray[currRowIndex].value*bXpose.smArray[currColIndex].value;
   currRowIndex++; currColIndex++;
  }
  while (smArray[currRowIndex].row == currRowA)
   currRowIndex++;
  currRowBegin = currRowIndex;
  currRowA = smArray[currRowIndex].row;
 }
 return d;
}

int main(int argc, char **argv)
{
 ifstream text_a, text_b;
 text_a.open(argv[1]);
 
 int arow, acol;
 text_a >> arow >> acol;
 SparseMatrix matrix1(arow, acol, 4);
 for (int i = 0; i < 4; i++)
 {
  int h, j, k;
  text_a >> h >> j >> k;
  matrix1.StoreMatrix(i, h, j, k);
 }
 text_a.close();

 text_b.open(argv[2]);

 int brow, bcol;
 text_b >> brow >> bcol;

 SparseMatrix matrix2(brow, bcol, 3);
 for (int i = 0; i < 3; i++)
 {
  int h, j, k;
  text_b >> h >> j >> k;
  matrix2.StoreMatrix(i, h, j, k);
 }
 text_b.close();

 SparseMatrix multipl = matrix1.Multiply(matrix2);

 cout << (multipl).rows << " " << (multipl).cols << " " << endl;
 
 for (int i = 0; i < (multipl).terms; i++)
  cout << (multipl).smArray[i].row << " " << (multipl).smArray[i].col << " " << (multipl).smArray[i].value << endl;

 return 0;
} 

