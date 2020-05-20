package ceng.ceng351.labdb;

import java.util.ArrayList;

public class Bucket {
    private int i, m;
    private ArrayList<Student> records;

    public Bucket(int m)
    {
        this.m = m;
        i = 1;
        records = new ArrayList<>(0);
    }
    public int getI() {
        return i;
    }

    public void setI(int i) {
        this.i = i;
    }

    public ArrayList<Student> getRecords() {
        return records;
    }
    public void setRecords(ArrayList<Student> s)
    {
        records = s;
    }
    public void add(Student s)
    {
        if (isFull())
            throw new ArrayIndexOutOfBoundsException("Bucket is full!");
        records.add(s);
    }
    public void remove(Student s)
    {
        for (Student r:records
             ) {
            if(s.getKey() == r.getKey())
            {
                records.remove(r);
                return;
            }
        }
        return;
    }
    public boolean isFull()
    {
        return records.size() >= m;
    }
    public boolean isEmpty()
    {
        return records.size() <= 0;
    }
    public int getBuddy(int h)
    {
        if((h & (1 << (i-1))) > 0)
            return h & ~(1 << (i-1));
        return h | (1 << (i-1));
    }
    public void printBucket()
    {
        System.out.print("[Local depth:"+i+"]");
        for (Student s: records
             ) {
            System.out.print("<"+s.getValue()+">");
        }
    }
}
