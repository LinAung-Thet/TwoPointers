// https://leetcode.com/problems/rotating-the-box/description/?envType=problem-list-v2&envId=two-pointers

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rowCount = boxGrid.size();
        int colCount = boxGrid[0].size();

        char stone = '#';
        char obstacle = '*';
        char empty = '.';

        vector<vector<char>> rotated(colCount, vector<char>(rowCount, empty));

        // Traverse all rows, staring from the last
        for( int i = rowCount - 1; i >= 0; i--) {
            int empCount = 0;
            
            // Traverse all columns, starting from the last
            for( int j = colCount - 1; j >= 0; j--) {
                // Count the empty spaces
                if( boxGrid[i][j] == empty)
                    ++empCount;
                // Shift the stones according to the number of empty spaces
                else if(boxGrid[i][j] == stone) {
                    rotated[j + empCount][rowCount - 1 - i] = stone;
                }                    
                // Add and reset the empty spaces once an obstacle is found
                else {
                    rotated[j + 0][rowCount - 1 - i] = obstacle;
                    empCount = 0;
                }
            }
        }

        // Return the answer
        return rotated;
    }
};
// Test cases
int main() {
    Solution solution;
    vector<vector<char>> boxGrid;
    vector<vector<char>> rotated;
    int m, n;

    cout << "Test case 1" << endl;
    boxGrid = {{'#','.','#'}};
    cout << "Expected : [[.][#][#]]" << "" << endl;
    rotated = solution.rotateTheBox(boxGrid);
    m = rotated.size(); 
    if( m > 0) n = rotated[0].size();
    cout << "Result   : [";
    for(int i = 0; i < m; ++i) {
        cout << "[";
        for( int j = 0; j < n; ++j) 
            cout << rotated[i][j] << "";
        cout << "]";
    }
    cout << "] " << endl << endl;

    cout << "Test case 2" << endl;
    boxGrid = {{'#','.','*','.'},{'#','#','*','.'}};
    cout << "Expected : [[#.][##][**][..]]" << "" << endl;
    rotated = solution.rotateTheBox(boxGrid);
    m = rotated.size(); 
    if( m > 0) n = rotated[0].size();
    cout << "Result   : [";
    for(int i = 0; i < m; ++i) {
        cout << "[";
        for( int j = 0; j < n; ++j) 
            cout << rotated[i][j] << "";
        cout << "]";
    }
    cout << "] " << endl << endl;

    cout << "Test case 3" << endl;
    boxGrid = {{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}};
    cout << "Expected : [[.##][.##][##*][#*.][#.*][#..]]" << "" << endl;
    rotated = solution.rotateTheBox(boxGrid);
    m = rotated.size(); 
    if( m > 0) n = rotated[0].size();
    cout << "Result   : [";
    for(int i = 0; i < m; ++i) {
        cout << "[";
        for( int j = 0; j < n; ++j) 
            cout << rotated[i][j] << "";
        cout << "]";
    }
    cout << "] " << endl << endl;
}