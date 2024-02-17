#include <Python.h>
#include <stdio.h>

/* Function to print basic information about Python lists */
void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        fprintf(stderr, "  [ERROR] Invalid PyListObject\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    PyObject *type = Py_TYPE(p);

    printf("[*] Python list info\n");
    printf("  [INFO] Size of the Python List = %ld\n", size);
    printf("  [INFO] Allocated = %ld\n", ((PyListObject *)p)->allocated);
    for (Py_ssize_t i = 0; i < size; ++i) {
        printf("  Element %ld: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
    }
}

/* Function to print basic information about Python bytes */
void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "  [ERROR] Invalid PyBytesObject\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    char *bytes = PyBytes_AsString(p);

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", bytes);
    printf("  first 10 bytes:");
    for (Py_ssize_t i = 0; i < size && i < 10; ++i) {
        printf(" %02x", bytes[i] & 0xff);
    }
    printf("\n");
}

/* Function to print basic information about Python float objects */
void print_python_float(PyObject *p) {
    if (!PyFloat_Check(p)) {
        fprintf(stderr, "  [ERROR] Invalid PyFloatObject\n");
        return;
    }

    double value = PyFloat_AsDouble(p);

    printf("[.] float object info\n");
    printf("  value: %f\n", value);
}

