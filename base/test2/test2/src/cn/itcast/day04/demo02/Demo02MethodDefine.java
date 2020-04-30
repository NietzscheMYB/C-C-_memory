package cn.itcast.day04.demo02;

/*
方法好比一个工厂
蒙牛工厂   原料，奶牛，饲料，水
            产出物，奶制品

 */

//两个int数字相加的方法

public class Demo02MethodDefine {
    public static void main(String[] args) {
        System.out.println(sum(10,11));
    }
    public static int sum(int a,int b) {
        System.out.println("方法执行");
        return a+b;
    }
    public static int sum(int a,int b,int c) {
        System.out.println("方法执行");
        return a+b+c;
    }
}
