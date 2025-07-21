#include <iostream>

using namespace std;
#define Neighbour 8

int X, Y, d, surface[Neighbour], flag;
int evaluted_pos[] = {6, 7, 0, 1, 2}, numOfEvalutedPos = 5, position_dir[][3] = {{3, 2, 1}, {4, -1, 0}, {5, 6, 7}};

void read() {
    int x, y, s, pos;
    cin >> Y >> d;
    for(int i = 0; i < Neighbour; i++) {
        cin >> x >> y >> s;

        x -= (X-1);
        y -= (Y-1);
        pos = position_dir[x][y];
        surface[pos] = s;
        if(surface[pos]) {
            flag = 1;
        }
    }
}

int nextStep() {
    int cur_d = d;
    if(!flag) {
        return d;
    }

    while(true) {
        for(int i = 0; i < numOfEvalutedPos; i++) {
            int pos = ((cur_d+evaluted_pos[i])%8);
            if(surface[pos] == 1) {
                return pos;
            }
        }
        //counter clock rotation
        cur_d += 1;
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    while((cin >> X) && (X != -1)) {
        flag = 0;
        read();
        cout << nextStep() << endl;
    }
    return 0;
}
