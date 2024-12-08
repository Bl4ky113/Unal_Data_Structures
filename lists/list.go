package main

import (
    "fmt"
)

type List[t any] interface {
    Get(int) (t, error);
    Add(int, t) error;
    Delete(int) error;
    Set(t, int) error;
    Size() int;

    shadowCopy() error;
}

type ArrayList[t any] struct {
    arr []t;
    shadowArr []t;
    size int;
    capacity int;
}

func CreateArrayList [t any](capacity int) (*ArrayList[t]) {
    newArrayList := ArrayList[t]{
        make([]t, capacity, capacity),
        make([]t, capacity * 2, capacity * 2),
        0,
        capacity,
    }

    return &newArrayList
}

func (list *ArrayList[t]) Get (index int) (t, error) {
    var value t

    if index < 0 || index > list.size {
        return value, fmt.Errorf("%d INDEX OUT OF BOUNDS", index)
    }

    value = list.arr[index]

    return value, nil
}

func (list *ArrayList[t]) Add (index int, value t) error {
    if index < 0 || index > list.capacity {
        return fmt.Errorf("INDEX UNDER/OVER-FLOW\n")
    }

    if list.size + 1 == list.capacity {
        return fmt.Errorf("ARRAYLIST FULL\n")
    }
    
    i := 0
    for i = list.size - 1; i >= index; i-- {
        list.arr[i + 1] = list.arr[i]
    }

    list.arr[index] = value
    list.size = list.size + 1

    return nil
}

func (list *ArrayList[t]) Delete (index int) error {
    if index < 0 || index > list.size - 1 {
        return fmt.Errorf("INDEX UNDER/OVER-FLOW\n")
    }

    i := 0
    for i = 0; i >= list.size - 1; i++ {

    }

    return nil
}

func (list *ArrayList[t]) Set (index int, value t) error {
    if index < 0 || index > list.capacity - 1 {
        return fmt.Errorf("INDEX UNDER/OVER-FLOW\n")
    }

    list.arr[index] = value

    return nil
}

func (line *ArrayList[t]) Size () int {
    return line.size
}

func main () {
    var val int

    list := CreateArrayList[int](10)
    list.Add(0, 100)
    list.Add(2, 200)
    list.Add(5, 500)
    
    val, _ = list.Get(0)
    fmt.Printf("%d\n", val)
    val, _ = list.Get(3)
    fmt.Printf("%d\n", val)
    val, _ = list.Get(5)
    fmt.Printf("%d\n", val)

    val = list.Size()
    fmt.Printf("%d\n", val)

    list.Set(0, 50)
    val, _ = list.Get(0)
    fmt.Printf("%d\n", val)

    list.Set(9, 52)
    val, _ = list.Get(9)
    fmt.Printf("%d\n", val)

    return
}
