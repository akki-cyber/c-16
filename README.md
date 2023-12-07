# Main Function
def main(argv):
    gates = {
        'AND': AND_gate,
        'XOR': XOR_gate,
        'OR' : OR_gate,
    }

    # Check for the inputs
    if not ((len(argv) == 3) and (argv[0] in gates.keys()) and \
       (argv[1] in ['0', '1']) and (argv[2] in ['0', '1'])):
        print(f'Kindly check your arguments, {argv}')
        exit(-1)

    # Generate Input labels and Garbled table
    A_labels, B_labels = generate_labels(), generate_labels()
    O_labels, Garbled_table = garble_gate(gates[argv[0]], A_labels, B_labels)

    # Print the encoded values of A and B
    print(f'Encoded A ({len(A_labels[0])} bytes): {A_labels[int(argv[1])]}')
    print(f'Encoded B ({len(B_labels[0])} bytes): {B_labels[int(argv[2])]}')

    # Rest of the code remains unchanged
    # ...

    # Evaluation starts here
    A, B = int(argv[1]), int(argv[2])
    encoded_A = A_labels[A]
    encoded_B = B_labels[B]

    # Call the Evaluator
    encoded_O = evaluate_garbled_gate(Garbled_table, encoded_A,
                                      encoded_B, O_labels)
    O = O_labels.index(encoded_O)
    print(f'Output is {O}')

if __name__ == '__main__':
    main(sys.argv[1:])
