import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    # data = []
    # with open(sys.argv[1], "r") as file:
    #     database = csv.DictReader(file)
    #     for item in database:
    #         item["AGATC"] = int(item["AGATC"])
    #         item["AATG"] = int(item["AATG"])
    #         item["TATC"] = int(item["TATC"])
    #         item["TTTTTTCT"] = int(item["TTTTTTCT"])
    #         item["TCTAG"] = int(item["TCTAG"])
    #         item["GATA"] = int(item["GATA"])
    #         item["GAAA"] = int(item["GAAA"])
    #         item["TCTG"] = int(item["TCTG"])
    #     data.append(item)

    # TODO: Read DNA sequence file into a variable

    seq = {}

    with open(sys.argv[1], 'r') as file:
        database = csv.reader(file)
        for line in database:
            header = line
            header.pop(0)
            for item in header:
                seq[item] = 0
            break

    with open(sys.argv[2], "r") as sequences:
        str = sequences.read()

    # TODO: Find longest match of each STR in DNA sequence
    for key in seq:
        rep = longest_match(str, key)
        seq[key] = rep

    with open(sys.argv[1], 'r') as file:
        database = csv.DictReader(file)
        for item in database:
            equal = 0
            for key in seq:
                if int(item[key]) == seq[key]:
                    equal += 1
            if equal == len(seq):
                print(item['name'])
                exit()
        print("No match")

    """AGATC = longest_match(str, "AGATC")
    AATG = longest_match(str, "AATG")
    TATC = longest_match(str, "TATC")
    TTTTTTCT = longest_match(str, "TTTTTTCT")
    TCTAG = longest_match(str, "TCTAG")
    GATA = longest_match(str, "GATA")
    GAAA = longest_match(str, "GAAA")
    TCTG = longest_match(str, "TCTG")

    # TODO: Check database for matching profiles
    for i in range(len(data)):
        # print(data[i]["AGATC"], data[i]["AATG"], data[i]["TCTG"])
        if (data[i]["AGATC"] == AGATC and data[i]["AATG"] == AATG and data[i]["TATC"] == TATC and data[i]["TTTTTTCT"] == TTTTTTCT and data[i]["TCTAG"] == TCTAG and data[i]["GATA"] == GATA and data[i]["GAAA"] == GAAA and data[i]["TCTG"] == TCTG):
            print(data[i]['name'])
            sys.exit(0)
    print("No match")"""

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()