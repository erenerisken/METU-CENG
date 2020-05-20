package ceng.ceng351.labdb;


import java.util.ArrayList;

public class LabDB {

    private int i;
    private int m;
    private ArrayList<Pointer> directory;
    public LabDB(int bucketSize) {
        i = 1;
        m = bucketSize;
        directory = new ArrayList<Pointer>(0);
        directory.add(new Pointer(0, m));
        directory.add(new Pointer(1, m));
    }

    public void enter(String studentID) {
        if (!search(studentID).equals("-1"))
            return;
        Student s = new Student(studentID);
        int h = getHash(s.getKey(), i);
        Bucket b = directory.get(h).bucket;
        if (!b.isFull())
        {
            b.add(s);
            return;
        }
        if (directory.get(h).bucket.getI() == i) // case 1: i = i_j
        {
            Bucket b2 = new Bucket(m);
            ArrayList<Student> tmpRecords = b.getRecords();
            b.setRecords(new ArrayList<>(0));
            for (Student r:tmpRecords
                 ) {
                if(getHash(r.getKey(), i+1) == h)
                    b.add(r);
                else
                    b2.add(r);
            }
            b.setI(b.getI()+1);
            b2.setI(b.getI());
            //System.out.println("Spitted for " + studentID);
            ArrayList<Pointer> tmpPointers = new ArrayList<>(0);
            for (Pointer p:directory
                 ) {
                Pointer tmp = new Pointer(p.getPrefix() + (int)Math.pow(2, i), m);
                if (p.getPrefix() == h)
                {
                    tmp.bucket = b2;
                }
                else
                    tmp.bucket = p.bucket;
                tmpPointers.add(tmp);
            }
            directory.addAll(tmpPointers);
            i++;
            //printLab();
            enter(studentID);
            return;
        }
        else // case 2: i>i_j
        {
            int curI = b.getI();
            int curPrefix = getHash(h, curI);
            ArrayList<Student> tmpRecords = b.getRecords();
            b.setRecords(new ArrayList<>(0));
            curI++;
            b.setI(curI);
            Bucket b2 = new Bucket(m);
            b2.setI(curI);
            for (Student r:tmpRecords
                 ) {
                if (getHash(r.getKey(), curI) == curPrefix)
                    b.add(r);
                else
                    b2.add(r);
            }
            int newPrefix = curPrefix + (int)Math.pow(2, curI-1);
            for (Pointer p:directory
                 ) {
                if (getHash(p.getPrefix(), curI) == newPrefix)
                    p.bucket = b2;
            }
            //printLab();
            enter(studentID);
            return;
        }
    }

    public void leave(String studentID) {
        Student s = new Student(studentID);
        int h = getHash(s.getKey(), i);
        if(h >= directory.size())
            return;
        Bucket b = directory.get(h).bucket;
        b.remove(s);
        if(!b.isEmpty())
            return;
        if(b.getI()>1)
        {
            int localH = getHash(h, b.getI());
            int buddyIndex = b.getBuddy(localH);
            Bucket b2 = directory.get(buddyIndex).bucket;
            b2.setI(b2.getI()-1);
            for (Pointer p:directory
                 ) {
                if (p.bucket == b)
                    p.bucket = b2;
            }
        }
        do {
            for (Pointer p : directory
            ) {
                if (p.bucket.getI() >= i)
                    return;
            }
            i--;

            int n = directory.size();
            if (n > n / 2) {
                directory.subList(n / 2, n).clear();
            }
        }while(true);
    }

    public String search(String studentID) {
        Student s = new Student(studentID);
        int h = getHash(s.getKey(), i);
        if (h >= directory.size())
            return "-1";
        ArrayList<Student> records = directory.get(h).bucket.getRecords();
        for (Student r:records
             ) {
            if (r.getValue().equals(studentID))
                return directory.get(h).prefix2Binary(i);
        }
        return "-1";
    }

    public void printLab() {
        System.out.println("Global depth : " + i);
        for (Pointer p: directory
             ) {
            p.printPointer(i);
        }
    }
    private int getHash(int key, int i)
    {
        int mask = ~((~0) << i);
        return key & mask;
    }
}
