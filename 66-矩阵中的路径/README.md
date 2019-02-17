# 66-矩阵中的路径

## 题目

牛客OJ：[66-矩阵中的路径](https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

## 代码

```c++
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) { 
        vector<char> flags(rows*cols,0);
        bool condition=false;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                condition= (condition || isPath(matrix,flags,str,i,j,rows,cols) );
            }
        }

        return condition;    
    }

private:
    bool isPath(char *matrix,vector<char> flags,char* str,int x,int y,int rows, int cols) {
        // 越界的点
        if(x<0 || x>=rows || y<0 || y>=cols) { 
            return false;     
        }
 
        if( matrix[x*cols+y]== *str  &&  flags[x*cols+y]==0 ) {
            flags[x*cols+y]=1;
            // 字符串结尾了（最后一个满足的）
            if(*(str+1)==0) { 
                return true;
            }
 
            bool condition =isPath(matrix,flags,(str+1),x,y-1,rows,cols) ||
                isPath(matrix,flags,(str+1),x-1,y,rows,cols)||
                isPath(matrix,flags,(str+1),x,y+1,rows,cols)||
                isPath(matrix,flags,(str+1),x+1,y,rows,cols);           
            if(condition == false) {
                flags[x*cols+y]=0;
            }
            
            return condition;             
        }           
        else {
            return false;
        }
    }
};
```