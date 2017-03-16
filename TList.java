import java.util.*;

public class TList {
    public static void main(String[] args) {
        TList tl = new TList();
        tl.perform();
    }

    public void perform() {
        ArrayList<TObj> l = new ArrayList<>(10);
        for(int i=0;i<5;++i) {
            l.add(new TObj(i));
        }

        for(int j=0;j<10;j++) {
            System.out.println(l.get(j));
        }
    }

    class TObj {
        int d;
        public TObj(int d) {this.d = d;}
        public String toString() {
            return String.valueOf(d);
        }
    }
}
