''' 
This question asked in zoho interview
convert the given number into string
example: 1 = A, 26 = Z, 27 = AA, 1000 = ALL
'''


def create_content(number: int):
    output = ''
    while number > 26:
        number, rem = divmod(number, 26)
        output = chr(64+rem) + output
    output = chr(64+number) + output
    return output


if __name__ == '__main__':
    n = int(input("Enter the number: "))
    print(create_content(n))