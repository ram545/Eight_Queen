/**********************************************************************
* FILENAME: Eight_Queens.cpp
*
* DESCRIPTION/PURPOSE:
* Eight queens are to be placed on a 8x8 chess board in such a way that no queen checks against any other queen. No two queens should be in the same
* column or same row or same diagonal. No two queens should be in the adjacent position.
*
* AUTHOR: 20020298 | Rama Krishna Reddy | sabbella.krishna@wipro.com
* START DATE: 26/9/2018
* SUBMISSION DATE: 27/9/2018
*
* Design: (Explain below algorithm in steps)
* 1)Backtracking approach is used to accommodate all possible possibilities.
* 2)Success Situation : If we can successfully place one queen in each column.
* 3)Failure Situation : If there is no way to place a queen in one column.
* 4)We start with column 1 and place a queen in one column,increment column value and do a recursive call.
* 5)We place the queen in such a way that its not attacked by previous queen and so on the recursion continues.
* 6)Once column value is 8 that signifies that it has reached the success situation so we print it and go back one level up.
* 7)remove this queen and place a queen in a different block of that column and like that it checks all available possiblities.
* ...
*
* IMPORTANT NOTES:
*
**********************************************************************/

#include<iostream>
#include<cstring>
#define N 8
using namespace std;
void display(int Array[][N]);
void QueenSolve(int Array[][N],int col);
void GridBlock(int Arr[][N],int row,int col);
void GridUnblock(int Arr[][N],int row,int col);

int main(){
	int Arr[N][N]={0};
	QueenSolve(Arr,0);
	return 0;
}

//This function is responsible for decrementing the values by 1,that are under attack by a queen placed at (row,col).
void GridBlock(int Arr[][N],int row,int col)
{
	int i,j;
	//block horizontal grids
	for(i=(col+1);i<N;i++)
		Arr[row][i]-=1;
	//block vertical grids
	for(j=0;j<N;j++){
		if(j!=row)
            Arr[j][col]-=1;
	}
	//block diagonal grids(downwards)
	for(i=(row+1),j=(col+1);(i<N&&j<N);i++,j++)
		Arr[i][j]-=1;
	//block diagonal grids(upwards)
	for(i=(row-1),j=(col+1);(i>=0 && j<N);i--,j++)
        Arr[i][j]-=1;
}

//This function is responsible for incrementing the values by 1,that are under attack by a queen placed at (row,col).
//Undo all actions done by GridBlock.
void GridUnblock(int Arr[][N],int row,int col)
{
	int i,j;
	//unblock horizontal grids
	for(i=(col+1);i<N;i++)
		Arr[row][i]+=1;
	//unblock vertical grids
	for(j=0;j<N;j++){
		if(j!=row)
			Arr[j][col]+=1;
	}
	//unblock diagonal grids(downwards)
	for(i=(row+1),j=(col+1);(i<N&&j<N);i++,j++)
		Arr[i][j]+=1;
	//unblock diagonal grids(upwards)
	for(i=(row-1),j=(col+1);(i>=0 && j<N);i--,j++)
        Arr[i][j]+=1;
}

//This recursive function is for checking all possibilities of placing 8 queens in the grid.
void QueenSolve(int Arr[][N],int col)
{
	if(col==N)
		display(Arr);
	else{
		for(int i=0;i<N;i++){
			if(Arr[i][col]==0){
                Arr[i][col]=1;
				GridBlock(Arr,i,col);
				QueenSolve(Arr,++col);
				GridUnblock(Arr,i,--col);
                Arr[i][col]=0;
			}
		}
	}
}


//This function is to display the output in 8*8 grid.
void display(int Array[][N])
{
    static int count = 0;
    count++;
    cout << "::::::::: Solution Number " << count << " :::::::::\n" << endl;
	int i,j;
	for(i=0;i<N;i++)
	{
        cout << '\t';
		for(j=0;j<N;j++)
		{
			if(Array[i][j]<=0)
                cout << 0 << "  ";
            else
                cout << Array[i][j] << "  ";
		}
		cout << endl;
	}
	cout << '\n' << endl;
}

//No test cases available

/****************************** END OF FILE ***************************/
