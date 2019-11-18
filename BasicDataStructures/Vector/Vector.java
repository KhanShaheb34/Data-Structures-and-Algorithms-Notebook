public class Vector {
    private Object[] objects;
    private int size;
    private int capacity;

    public Vector() {
        capacity = 100;
        size = 0;
        objects = new Object[capacity];
    }

    public void push(Object object) {
        if(size == capacity){
            objects = resize(capacity * 2);
        }
        objects[size] = object;
        size++;
    }

    public void pop() {
        if (!isEmpty()) {
            size--;
            objects[size] = null;
        } else {
            System.err.println("Vector is empty!");
        }
    }

    public Object at(int index) {
        index--;
        if(index < size) return objects[index];
        else {
            System.err.println("Index is out of size!");
            return null;
        }
    }

    public int find(Object item) {
        for (int i = 0; i < size; i++) {
            if (objects[i] == item) return i+1;
        }
        System.err.println("Not Found!");
        return -1;
    }

    public void delete(int index) {
        index--;
        if (index >= size) {
            System.err.println("Index is out of bound!");
            return;
        }
        System.arraycopy(objects, index + 1, objects, index, size - 1 - index);
        size--;
        objects[size] = null;
    }

    public void insert(int index, Object item) {
        index--;
        if (index >= size) {
            System.err.println("Index is out of bound!");
            return;
        }
        for (int i = size; i > index; i--) {
            objects[i] = objects[i-1];
        }
        objects[index] = item;
        size++;
    }

    public void prepend(Object item) {
        insert(1, item);
    }

    public void remove(Object item) {
        if(find(item) != -1) delete(find(item));
    }

    public int getSize() {
        return size;
    }

    public int getCapacity() {
        return capacity;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private Object[] resize(int capacity){
        this.capacity = capacity;
        Object[] objects1 = new Object[capacity];
        System.arraycopy(objects, 0, objects1, 0, size);
        return objects1;
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder("Vector:");
        if (size == 0) return "Empty Vector!";
        for (int i = 0; i < size; i++) {
            str.append(" ").append(objects[i]);
        }
        str.append("\nSize: ").append(size);
        return str.toString();
    }
}
