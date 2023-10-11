public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        NewMain obj = new NewMain();
        obj.newMain();
    }
}

public class NewMain {
    public void newMain() {
        System.out.println("Hello from new World");
    }
}