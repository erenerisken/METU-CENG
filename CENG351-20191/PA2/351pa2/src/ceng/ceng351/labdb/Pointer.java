package ceng.ceng351.labdb;

public class Pointer {
    private int prefix;
    public Bucket bucket;
    public Pointer(int prefix, int m)
    {
        this.setPrefix(prefix);
        bucket = new Bucket(m);
    }

    public int getPrefix() {
        return prefix;
    }

    public void setPrefix(int prefix) {
        this.prefix = prefix;
    }
    public void printPointer(int i)
    {
        System.out.print(prefix2Binary(i) + " : ");
        bucket.printBucket();
        System.out.println("");
    }
    public String prefix2Binary(int i)
    {
        StringBuilder ret = new StringBuilder(Integer.toBinaryString(prefix));
        for (int j = ret.length(); j<i; j++)
        {
            ret.insert(0, "0");
        }
        return ret.toString();
    }
}
