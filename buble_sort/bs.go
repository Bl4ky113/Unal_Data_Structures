package main 

import (
    "fmt"
)

func BubbleSort (numArr *[]int) {
    var loopLength int = len(*numArr)

    for loopLength > 0 {
        var changedIndex int

        for i := 1; i < loopLength; i++ {
            if (*numArr)[i - 1] > (*numArr)[i] {
                temp := (*numArr)[i]
                (*numArr)[i] = (*numArr)[i - 1]
                (*numArr)[i - 1] = temp

                changedIndex = i
            }
        }

        loopLength = changedIndex
    }

    return
}

func main () {
    var lengthArr int
    fmt.Scanf("%d\n", &lengthArr)

    numArr := make([]int, 0, lengthArr)

    for i := 0; i < lengthArr; i++ {
        var input int
        fmt.Scanf("%d\n", &input)

        numArr = append(numArr, input)
    }

    fmt.Printf("%v\n", numArr)
    
    BubbleSort(&numArr)

    fmt.Printf("%v\n", numArr)

    return
}
