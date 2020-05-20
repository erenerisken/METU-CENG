package ceng.ceng351.labdb;

public class Student {
    private String value;
    private int key;

    public Student(String id)
    {
        value = id;
        key = Integer.parseInt(id.substring(1));
    }
    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }
}
