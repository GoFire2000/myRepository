import javax.swing.plaf.synth.SynthTextAreaUI;
import java.util.Scanner;
public class OthelloGame {
    static Scanner cin=new Scanner(System.in);

    //游戏模式选择
    static int modeChoose() {
        System.out.println("选择模式,请输入下列模式前数字选择模式!");
        System.out.println("1 玩家对战");
        System.out.println("2 人机对战");
        System.out.println("3 退出游戏\n");
        return cin.nextInt();
    }

    //玩家对战模式
    static void playerVsPlayerGame() {
        System.out.println("欢迎来到玩家对战");

        //输出初始棋盘
        CheckerBoard board = new CheckerBoard();
        System.out.println("初始棋盘如下");
        board.printChessBoard();

        int player = 1, nextPlayer = 2;//1为执黑子着，2为执白子者

        //一直运行直到游戏结束
        while (true) {
            //分别判断是否可以落白棋和黑棋，是为true，否为false
            boolean canPlay = false;
            boolean nextCanPlay = false;
            for (int i = 1; i <= board.N; i++) {
                for (int j = 1; j <= board.N; j++) {
                    if (board.judgeCanAddPiece(i, j, player) == true) canPlay = true;
                    if (board.judgeCanAddPiece(i, j, nextPlayer) == true) nextCanPlay = true;
                }
            }

            //无法落子，游戏结束
            if (canPlay == false && nextCanPlay == false) {
                System.out.println("游戏结束");
                if (board.numberOfWhite > board.numberOfBlack) System.out.println("执白子者获胜");
                else if (board.numberOfWhite == board.numberOfBlack) System.out.println("平局");
                else if (board.numberOfWhite < board.numberOfBlack) System.out.println("执黑子者获胜");
                board.printChessBoard();
                break;
            }

            //当前选手无法落子，直接落子权给对手
            if (canPlay == false) {
                if (player == 0) System.out.println("执黑子者无处可下，继续游戏");
                else System.out.println("执白子者无处可下，继续游戏");
                int cop = player;
                player = nextPlayer;
                nextPlayer = cop;
                board.printChessBoard();
                continue;
            }
            //玩家走黑子
            if (player == 1) {
                System.out.println("执黑子者走");

                System.out.println("请输入黑子坐标:");
                int posx = cin.nextInt(), posy = cin.nextInt();

                while (board.judgeCanAddPiece(posx, posy, player) == false) {//判断是否合法，不合法重新输入
                    System.out.println("坐标不合法，请重新输入");
                    System.out.println("请输入黑子坐标:");
                    posx = cin.nextInt();
                    posy = cin.nextInt();
                }

                board.addPiece(posx, posy, player);//落黑子，更新棋盘
            } else {//玩家走白子
                System.out.println("执白子者走");

                System.out.println("请输入白子坐标:");
                int posx = cin.nextInt(), posy = cin.nextInt();

                while (board.judgeCanAddPiece(posx, posy, player) == false) {//判断是否合法，不合法重新输入
                    System.out.println("坐标不合法，请重新输入");
                    System.out.println("请输入白子坐标:");
                    posx = cin.nextInt();
                    posy = cin.nextInt();
                    System.out.println();
                }

                board.addPiece(posx, posy, player);//落白子，更新棋盘
            }
            //更新出手者，输出棋盘
            int cop = player;
            player = nextPlayer;
            nextPlayer = cop;
            board.printChessBoard();
        }
    }

    //人机对战模式
    static void AIGame(){
        //玩家选择自己用什么棋子
        System.out.println("欢迎来到人机对战，请选择棋子");
        System.out.println("1 黑子");
        System.out.println("2 白子");
        int people=cin.nextInt();

        //输出初始棋盘
        CheckerBoard board=new CheckerBoard();
        System.out.println("初始棋盘如下");
        board.printChessBoard();

        int player=1,nextPlayer=2;//1为执黑子着，2为执白子者
        //一直运行直到游戏结束
        while(true) {
            //分别判断是否可以落白棋和黑棋，是为true，否为false
            boolean canPlay = false;
            boolean nextCanPlay = false;
            for (int i = 1; i <= board.N; i++) {
                for (int j = 1; j <= board.N; j++) {
                    if (board.judgeCanAddPiece(i, j, player) == true) canPlay = true;
                    if (board.judgeCanAddPiece(i, j, nextPlayer) == true) nextCanPlay = true;
                }
            }

            //无法落子，游戏结束
            if (canPlay == false && nextCanPlay == false) {
                System.out.println("游戏结束");
                if (board.numberOfWhite > board.numberOfBlack) System.out.println("执白子者获胜");
                else if (board.numberOfWhite == board.numberOfBlack) System.out.println("平局");
                else if (board.numberOfWhite < board.numberOfBlack) System.out.println("执黑子者获胜");

                board.printChessBoard();
                break;
            }

            //当前选手无法落子，直接落子权给对手
            if (canPlay == false) {
                if (player == 0) System.out.println("执黑子者无处可下，继续游戏");
                else System.out.println("执白子者无处可下，继续游戏");

                int cop = player;
                player = nextPlayer;
                nextPlayer = cop;
                board.printChessBoard();

                continue;
            }

            //黑子走
            if (player == 1) {
                System.out.println("执黑子者走");
                if (people != 1) {//人机走黑子
                    //新建一个棋盘，将原棋盘保存至新棋盘
                    CheckerBoard cop = new CheckerBoard();
                    cop.copy(board);

                    //贪心算法选择
                    int posx = 0, posy = 0, max = cop.numberOfBlack - cop.numberOfWhite;

                    for (int i = 1; i <= board.N; i++) {
                        for (int j = 1; j <= board.N; j++) {
                            if (cop.judgeCanAddPiece(i, j, player) == false) continue;
                            board.copy(cop);
                            board.addPiece(i, j, player);
                            //贪心选择
                            if (board.numberOfBlack - board.numberOfWhite > max) {
                                max = board.numberOfBlack - board.numberOfWhite;
                                posx = i;
                                posy = j;
                            }
                        }
                    }
                    board.copy(cop);
                    System.out.println("黑子位置  " + posx + " " + posy);
                    board.addPiece(posx, posy, player);
                }
                else {
                    //玩家走黑子
                    System.out.println("请输入黑子坐标:");
                    int posx = cin.nextInt(), posy = cin.nextInt();

                    while (board.judgeCanAddPiece(posx, posy, player) == false) {
                        System.out.println("坐标不合法，请重新输入");
                        System.out.println("请输入黑子坐标:");
                        posx = cin.nextInt();
                        posy = cin.nextInt();
                    }
                    board.addPiece(posx, posy, player);
                }
            } else {
                System.out.println("执白子者走");
                if (people != 2) {//人机走白子
                    //新建一个棋盘，将原棋盘保存至新棋盘
                    CheckerBoard cop = new CheckerBoard();
                    cop.copy(board);

                    int posx = 0, posy = 0, max = cop.numberOfWhite - cop.numberOfBlack;

                    //贪心算法选择
                    for (int i = 1; i <= board.N; i++) {
                        for (int j = 1; j <= board.N; j++) {
                            if (cop.judgeCanAddPiece(i, j, player) == false) continue;
                            board.copy(cop);
                            board.addPiece(i, j, player);
                            //贪心选择
                            if (board.numberOfWhite - board.numberOfBlack > max) {
                                max = board.numberOfWhite - board.numberOfBlack;
                                posx = i;
                                posy = j;
                            }
                        }
                    }
                    board.copy(cop);
                    System.out.println("白子位置  " + posx + " " + posy);
                    board.addPiece(posx, posy, player);
                }
                else {
                    //玩家走白子
                    System.out.println("请输入白子坐标:");
                    int posx = cin.nextInt(), posy = cin.nextInt();
                    while (board.judgeCanAddPiece(posx, posy, player) == false) {
                        System.out.println("坐标不合法，请重新输入");
                        System.out.println("请输入白子坐标:");
                        posx = cin.nextInt();
                        posy = cin.nextInt();
                        System.out.println();
                    }
                    board.addPiece(posx, posy, player);
                }
            }
            //更新出手者，输出棋盘
            int cop = player;
            player = nextPlayer;
            nextPlayer = cop;
            board.printChessBoard();
        }
    }

    //主函数，游戏开始
    public static void main(String[] args) {
        while (true) {
            System.out.println("=========欢迎来到黑白棋小游戏!=========\n");
            int type = modeChoose();//模式选择
            if (type == 1) playerVsPlayerGame();//玩家对战模式
            else if (type == 2) AIGame();//人机对战模式
            else if (type == 3) {//退出游戏
                System.out.println("=========游戏结束，感谢体验!=========\n");
                break;
            } else {
                System.out.println("选择错误，请重新选择!");
            }
        }
    }
}
