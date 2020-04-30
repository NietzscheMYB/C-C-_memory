package cn.itcast.day04.demo02;


/*

定义方法
public static void 方法名称（）{}

调用格式
方法名称（）；




*/




public class Demo01Method {
    public static void main (String[] args){
        printMethod();
    }
    public static void printMethod(){
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 20; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
