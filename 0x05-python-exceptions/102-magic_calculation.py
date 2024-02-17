def magic_calculation(a, b):
    result = 0  # Equivalent to LOAD_CONST 1 (0) and STORE_FAST 2 (result)

    for i in range(1, 3):  # Equivalent to LOAD_CONST 2 (1), LOAD_CONST 3 (3), CALL_FUNCTION 2, and GET_ITER
        try:  # Equivalent to SETUP_EXCEPT 49 (to 80)
            if i > a:  # Equivalent to LOAD_FAST 3 (i), LOAD_FAST 0 (a), and COMPARE_OP 4 (>)
                raise Exception('Too far')  # Equivalent to LOAD_GLOBAL 1 (Exception), LOAD_CONST 4 ('Too far'), CALL_FUNCTION 1, and RAISE_VARARGS 1
        except:  # Equivalent to POP_TOP, POP_TOP, and POP_TOP
            pass

        result += (a ** b) / i  # Equivalent to LOAD_FAST 2 (result), LOAD_FAST 0 (a), LOAD_FAST 1 (b), BINARY_POWER, LOAD_FAST 3 (i), BINARY_TRUE_DIVIDE, INPLACE_ADD, and STORE_FAST 2 (result)

    result += a + b  # Equivalent to LOAD_FAST 2 (result), LOAD_FAST 1 (b), LOAD_FAST 0 (a), BINARY_ADD, and STORE_FAST 2 (result)

    return result  # Equivalent to LOAD_FAST 2 (result) and RETURN_VALUE

