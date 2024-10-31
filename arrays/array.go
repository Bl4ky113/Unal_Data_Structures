package main

import (
    "fmt"
)

const (
    arrSize = 50
    arrCapacity = 50
)

func main () {
    arr := make([]int, arrSize, arrCapacity)

    fmt.Printf("%v\n", arr)
    fmt.Printf("%d\t%d\n", len(arr), cap(arr))

    arr = append(arr, 100)

    fmt.Printf("%v\n", arr)
    fmt.Printf("%d\t%d\n", len(arr), cap(arr))

    return;
}
