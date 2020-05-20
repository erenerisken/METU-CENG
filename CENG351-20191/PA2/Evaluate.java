package ceng.ceng351.labdb;

public class Evaluate {

    public static void main(String[] args) {
        LabDB labdb = new LabDB(4);
        try {
            labdb.enter("e4");
            labdb.enter("e12");
            labdb.enter("e32");
            labdb.enter("e16");
            labdb.enter("e1");
            labdb.enter("e5");
            labdb.enter("e21");
            labdb.enter("e10");
            labdb.enter("e15");
            labdb.enter("e7");
            labdb.enter("e19");
            System.out.println(labdb.search("e21"));
            labdb.enter("e13");
            labdb.enter("e20");
            labdb.enter("e9");
            //System.out.println(labdb.search("e20"));
            //System.out.println(labdb.search("e10101010"));
            //System.out.println(labdb.search("e16"));
            labdb.printLab();
            labdb.leave("e32");
            labdb.leave("e16");
            labdb.printLab();
            labdb.leave("e10");
            labdb.leave("e9");
            labdb.leave("e1");
            labdb.leave("e4");
            labdb.leave("e12");
            labdb.leave("e20");
            labdb.leave("e5");
            labdb.leave("e21");
            labdb.leave("e13");
            labdb.printLab();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
