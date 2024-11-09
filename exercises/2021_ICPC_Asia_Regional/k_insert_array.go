package main

import (
    "fmt"
    "strings"
    "math"
)

const (
    ModMask = 1234567
)

func createInsertionArray (strInsert, strTemplate string) []string {
    insertionArray := make([]string, 0, len(strTemplate) + 1)

    for i := 0; i < len(strTemplate) + 1; i++ {
        var sb strings.Builder

        sb.WriteString(strTemplate[0:i])
        sb.WriteString(strInsert)
        sb.WriteString(strTemplate[i:])

        insertionArray = append(insertionArray, sb.String())
    }

    return insertionArray
}

func sortInsertionArray (insArr *[]string) {
    for i := 0; i < len(*insArr); i++ {
        for j := 0; j < len(*insArr); j++ {
            for k := 0; k < len((*insArr)[j]); k++ {
                if (*insArr)[i][k] <= (*insArr)[j][k] {
                    continue
                }

                temp := (*insArr)[j]
                (*insArr)[j] = (*insArr)[i]
                (*insArr)[i] = temp
            }
        }
    }

    return
}

func getInsertionArrayResult (str1, str2 string) int {
    var result int
    insertionArray := createInsertionArray(str1, str2)
    sortInsertionArray(&insertionArray)

    fmt.Printf("%v\n", insertionArray)

    for i := 0; i < len(insertionArray); i++ {
        numStr := 0

        for j := 0; j < len(insertionArray[i]); j++ {
            numStr += int(insertionArray[i][j])
        }
        
        result += ( numStr * int( math.Pow(float64(ModMask), float64(i)) ) )
    }

    return result % (int( math.Pow10(9) ) + 7)
}

func main () {
    var numInputs int

    fmt.Scanf("%d\n", &numInputs)

    for i := 0; i < numInputs; i++ {
        var str1, str2 string

        fmt.Scanf("%s\n", &str1)
        fmt.Scanf("%s\n", &str2)

        result := getInsertionArrayResult(str1, str2)

        fmt.Printf("%d\n", result)
    }

    return
}
