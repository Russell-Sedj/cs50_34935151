# TODO

from cs50 import get_string


def main():
    text = get_string("Text: ")

    l = count_letters(text)
    w = count_words(text)
    s = count_sentences(text)
    L = (l * 100) / w
    S = (s * 100) / w
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def count_letters(text):
    len = 0
    for x in text:
        if x.isalpha():
            len += 1
    return len


def count_words(text):
    len = 1
    for x in text:
        if x.isspace():
            len += 1
    return len


def count_sentences(text):
    len = 0
    for x in text:
        if x == '.' or x == '?' or x == '!':
            len += 1
    return len


if __name__ == "__main__":
    main()