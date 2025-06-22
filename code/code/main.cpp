////#include <vector>
////#include <string>
////#include <iostream>
////using namespace std;
////
////class Solution
////{
////    vector<bool> row;//记录 一列里面 是否已经有皇后
////    vector<bool> zjj;//记录 该y=x+b这条线上 是否已经有皇后，记录它的截距b
////    vector<bool> fjj;//记录 该y=-x+b这条线上 是否已经有皇后，记录它的截距b
////    vector<vector<string>> ret;
////    vector<string> path;
////
////    int CONST;//一个常量，用于辅助b
////public:
////    vector<vector<string>> solveNQueens(int n)
////    {
////        CONST = 100;
////        row.resize(n, false);
////        zjj.resize(n + CONST, false);
////        fjj.resize(n + CONST, false);
////        path.resize(n);
////        for (int i = 0; i < path.size(); i++)
////        {
////            path[i].resize(n, '.');
////        }
////        dfs(0);
////        return ret;
////    }
////
////    void dfs(int pos)
////    {
////        if (pos == path.size())
////        {
////            ret.push_back(path);
////            return;
////        }
////
////        for (int i = 0; i < path[pos].size(); i++)
////        {
////            int zhengjieju = i - pos + 8;
////            int fujieju = i + pos + 8;
////
////            if (row[i] == false && zjj[zhengjieju] == false && fjj[fujieju] == false)
////            {
////                path[pos][i] = 'Q';
////                row[i] = true;
////                zjj[zhengjieju] = fjj[fujieju] = true;
////                dfs(pos + 1);
////                path[pos][i] = '.';
////                row[i] = false;
////                zjj[zhengjieju] = fjj[fujieju] = false;
////            }
////        }
////    }
////};
////
////int main()
////{
////    vector<vector<string>> ret = Solution().solveNQueens(5);
////    cout << "!!!" << endl;
////    return 0;
////}
//
//#include <vector>
//#include <string>
//#include <iostream>
//using namespace std;
//
//class Solution
//{
//    bool row[9][10];//记录一行中，已经出现的数 和 未出现的数    例如 row[4][7] == true 的意思是，在第4行中，7这个数已经出现过了
//    bool col[9][10];//记录一列中
//    bool visited[3][3][10];//记录一个 3*3 的方格
//    vector<vector<char>> tmpboard;
//
//public:
//    void solveSudoku(vector<vector<char>>& board)
//    {
//        tmpboard = board;
//
//        //先遍历一遍board
//        for (int i = 0; i < tmpboard.size(); i++)
//        {
//            for (int j = 0; j < tmpboard[i].size(); j++)
//            {
//                if (tmpboard[i][j] != '.')
//                {
//                    int tmp = tmpboard[i][j] - '0';
//                    row[i][tmp] = col[j][tmp] = visited[i / 3][j / 3][tmp] = true;
//                }
//            }
//        }
//
//        dfs(tmpboard, 0, 0,board);
//        return;
//    }
//
//    void dfs(vector<vector<char>>& tmpboard, int hang, int lie, vector<vector<char>>& board)
//    {
//        for (int i = hang; i < tmpboard.size(); i++)
//        {
//            for (int j = lie; j < tmpboard[i].size(); j++)
//            {
//                if (tmpboard[i][j] == '.')
//                {
//                    int k = 1;
//                    for (k = 1; k <= 9; k++)
//                    {
//                        if (row[i][k] == false && col[j][k] == false && visited[i / 3][j / 3][k] == false)
//                        {
//                            row[i][k] = col[j][k] = visited[i / 3][i / 3][k] = true;
//                            tmpboard[i][j] = '0' + k;
//
//                            if (j == tmpboard[i].size() - 1)
//                            {
//                                dfs(tmpboard, i + 1, 0, board);
//                                row[i][k] = col[j][k] = visited[i / 3][i / 3][k] = false;
//                                tmpboard[i][j] = '.';
//                            }
//                            else
//                            {
//                                dfs(tmpboard, i, j + 1, board);
//                                row[i][k] = col[j][k] = visited[i / 3][i / 3][k] = false;
//                                tmpboard[i][j] = '.';
//                            }
//                        }
//                    }
//                    if (k == 10)
//                    {
//                        return;
//                    }
//                }
//                if (i == 8 && j == 8)
//                {
//                    board = tmpboard;
//                }
//            }
//        }
//    }
//};
//
//int main()
//{
//    vector<vector<char>> board = { {'5', '3', '.',      '.', '7','.',       '.', '.','.'},
//                                   {'6', '.', '.',      '1', '9','5',       '.', '.','.'},
//                                   {'.', '9', '8',      '.', '.','.',       '.', '6','.'},
//
//                                   {'8', '.', '.',      '.', '6','.',       '.', '.','3'},
//                                   {'4', '.', '.',      '8', '.','3',       '.', '.','1'},
//                                   {'7', '.', '.',      '.', '2','.',       '.', '.','6'},
//
//                                   {'.', '6', '.',      '.', '.','.',       '2', '8','.'},
//                                   {'.', '.', '.',      '4', '1','9',       '.', '.','5'},
//                                   {'.', '.', '.',      '.', '8','.',       '.', '7','9'} };
//
//    Solution().solveSudoku(board);
//
//    cout << "result" << endl;
//
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool visited[15][15];
    int num;//黄金数量最大值
    int nownum;//当前正在走的路的值

public:
    int getMaximumGold(vector<vector<int>>& grid)
    {
        num = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != 0)
                {
                    visited[i][j] = true;
                    nownum = 0;
                    nownum += grid[i][j];
                    dfs(grid, i, j);
                    visited[i][j] = false;
                }
            }
        }
        return num;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        int dx[4] = { 0,0,1,-1 };//右，左，下，上
        int dy[4] = { 1,-1,0,0 };

        int k = 0;
        for (k = 0; k < 4; k++)
        {
            int nexti = i + dx[k];
            int nextj = j + dy[k];
            if (nexti >= 0 && nexti < grid.size()
                && nextj >= 0 && nextj < grid[nexti].size()
                && visited[nexti][nextj] != true
                && grid[nexti][nextj] != 0)
            {
                visited[nexti][nextj] = true;
                nownum += grid[nexti][nextj];
                dfs(grid, nexti, nextj);
                nownum -= grid[nexti][nextj];
                visited[nexti][nextj] = false;
            }
        }

        //说明 上下左右都走不通了，无路可走了
        if (k == 4)
        {
            if (nownum > num)
                num = nownum;
        }
    }
};

int main()
{
    vector<vector<int>> grid = { {0,6,0}, {5,8,7}, {0,9,0} };
    int ret = Solution().getMaximumGold(grid);
	return 0;
}