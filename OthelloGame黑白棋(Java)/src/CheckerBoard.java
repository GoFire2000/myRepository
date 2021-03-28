public class CheckerBoard {

    final static int N=8;//棋盘大小，n*n
    final static int[] DX={0,0,-1,1,-1,-1,1,1};//8个方向坐标变换
    final static int[] DY={1,-1,0,0,-1,1,-1,1};

    int[][] tp;//棋盘类型，0为空，1为黑子，2为白字

    int numberOfBlack,numberOfWhite;//黑子的个数，白子的个数
    //初始化块
    {
        numberOfBlack = 2;
        numberOfWhite = 2;

        //开始时在棋盘正中有两白两黑四个棋子交叉放置
        tp = new int[10][10];
        tp[4][4] = tp[5][5] = 1;
        tp[4][5] = tp[5][4] = 2;
    }

    //将整个棋盘内容复制
    void copy(CheckerBoard board) {
        numberOfBlack = board.numberOfBlack;
        numberOfWhite = board.numberOfWhite;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                tp[i][j] = board.tp[i][j];
            }
        }
    }

    //在(posx,posy)位置放置一个类型为type的棋子
    void addPiece(int posx,int posy,int type) {
        tp[posx][posy] = type;
        int nextType = ((type == 1) ? 2 : 1);//不同的棋子类型

        for (int i = 0; i < 8; i++) {//向八个方向分别拓展 更新
            int dx = DX[i], dy = DY[i];
            int xx = posx + dx, yy = posy + dy;
            boolean flag1 = false;//判断中间是否有空
            boolean flag2 = false;//判断延伸是否有type类型的棋子

            while ((xx >= 1 && xx <= N) && (yy >= 1 && yy <= N)) {
                if (tp[xx][yy] == 0) {
                    flag1 = true;
                    break;
                }
                if (tp[xx][yy] == type) {
                    flag2 = true;
                    break;
                }
                xx += dx;
                yy += dy;
            }

            if (flag1 == true) continue;//中间有空
            if (flag2 == false) continue;//延伸没有type类型
            xx = posx + dx;
            yy = posy + dy;
            while ((xx >= 1 && xx <= N) && (yy >= 1 && yy <= N)) {
                if (tp[xx][yy] == 0) break;
                if (tp[xx][yy] == type) break;
                tp[xx][yy] = type;//黑白翻转
                xx += dx;
                yy += dy;
            }
        }
        //重新统计黑白棋子的个数
        numberOfWhite = 0;
        numberOfBlack = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (tp[i][j] == 1) numberOfBlack++;
                else if (tp[i][j] == 2) numberOfWhite++;
            }
        }
    }

    //判断能否在(posx,posy)位置放置一个类型为type的棋子
    boolean judgeCanAddPiece(int posx,int posy,int type) {
        if (posx<1 || posx>N || posy<1 || posy>N || tp[posx][posy] != 0) return false;
        int nextType = ((type == 1) ? 2 : 1);//不同的棋子类型
        boolean okAny = false;//任何一个方向延伸可以都为true

        for (int i = 0; i < 8; i++) {//8个方向分别拓展判断，如果一个方向可行，则可以在此处落子
            int dx = DX[i], dy = DY[i];
            int xx = posx + dx, yy = posy + dy;
            boolean flag1 = false;//判断中间是否有空
            boolean flag2 = false;//判断延伸是否有type类型的棋子
            boolean flag3 = false;//判断延伸是否有nextType类型棋子

            while ((xx >= 1 && xx <= N) && (yy >= 1 && yy <= N)) {
                if (tp[xx][yy] == 0) {
                    flag1 = true;
                    break;
                }
                if (tp[xx][yy] == type) {
                    flag2 = true;
                    break;
                }
                flag3 = true;
                xx += dx;
                yy += dy;
            }
            if (flag1 == true) continue;//中间有空
            if (flag2 == false) continue;//延伸没有type类型
            if (flag3 == false) continue;//两个type类型相邻，中间没有nextType类型
            okAny = true;
            break;
        }
        return okAny;
    }

    //将整个棋盘输出，+表示空白   ●表示黑子    ○表示白子
    void printChessBoard() {
        System.out.print(" ");
        for (int i = 1; i <= N; i++) System.out.print(" " + i);//列号
        System.out.println();
        for (int i = 1; i <= N; i++) {
            System.out.print(i + " ");//行号
            for (int j = 1; j <= N; j++) {
                if (tp[i][j] == 0) System.out.print("+ ");
                else if (tp[i][j] == 1) System.out.print("● ");
                else if (tp[i][j] == 2) System.out.print("○ ");
            }
            System.out.println();
        }

        System.out.println("\n黑子个数" + numberOfBlack + "      " + "白子个数" + numberOfWhite);
        System.out.println("+:空白   ●：黑子    ○：白子\n==================================================\n");
    }
}
