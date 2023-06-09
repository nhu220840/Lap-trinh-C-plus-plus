#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;
int a[100][100];

void loang(int i, int j){
    a[i][j] = 0; //danh dau la da duyet qua phan tu nay
    for(int k = 0; k < 4; k++){
        //Xet 4 o chung canh
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        //Kiem tra xem toa do nay con nam trong ma tran ko?
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 1)
            loang(i1, j1); //de quy de loang tiep den nhung o 1 ben canh
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                cnt++; //tim thay mien co so 1
                loang(i, j); //loang den nhung o 1 ben canh va danh dau cho no = 0
            }
        }
    }
    cout << cnt;
}