
"""
    El algoritmo de Thanos es un algoritmo de “ordenamiento” que recibe como entrada una lista de enteros y 
    la procesa de la siguiente manera: si la lista se encuentra ordenada de menor a mayor, la deja como está 
    y termina. En caso contrario, divide la lista en mitades (mitad izquierda y mitad derecha), elimina una 
    de las mitades y repite el proceso sobre la mitad restante. Nótese que en caso de que la lista tenga 
    tamaño impar, la mitad derecha tendrá un dato más que la mitad izquierda.

    Escriba un programa que reciba como entrada una lista de enteros L, y determine la longitud de la lista 
    más larga posible que puede obtenerse como resultado de aplicar el algoritmo de Thanos sobre L.
"""

INPUT_SEPARATOR = " "

def handle_user_input ():
    number_list = []
    
    str_input = input().strip()
    for str_number in str_input.split(INPUT_SEPARATOR):
        number_list.append(int(str_number))

    return number_list

def thanos_sort (number_list):
    if len(number_list) == 1:
        return 1

    list_sorted = True
    for i in range(len(number_list) - 1):
        if number_list[i] > number_list[i + 1]:
            list_sorted = False
            break

    if list_sorted:    
        return len(number_list)

    max_len_right = thanos_sort(number_list[len(number_list)//2:])
    max_len_left = thanos_sort(number_list[:len(number_list)//2])

    return max_len_left if max_len_left > max_len_right else max_len_right

def main ():
    number_list = handle_user_input()

    max_len = thanos_sort(number_list)
    print(max_len)
    return

if __name__ == "__main__":
    main()
