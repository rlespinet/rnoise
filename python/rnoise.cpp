#include <Python.h>
#include "structmember.h"

#include <iostream>
#include <cstring>

#include "numpy/npy_no_deprecated_api.h"

#define PY_ARRAY_UNIQUE_SYMBOL MODULE_ARRAY_API
#include "numpy/arrayobject.h"

#include "rnoise.hpp"

static char module_docstring[] = "Functions related to noise generation";
static char perlin_docstring [] = "Perlin noise";

static PyObject *rnoise_perlin_bind(PyObject *self, PyObject *args, PyObject *kwargs);

static PyMethodDef rnoise_methods[] = {

    {"Perlin", (PyCFunction) rnoise_perlin_bind, METH_VARARGS | METH_KEYWORDS, perlin_docstring},
    {nullptr, nullptr, 0, nullptr}
};

static struct PyModuleDef rnoise_module = {
    PyModuleDef_HEAD_INIT,
    "rnoise",
    module_docstring,
    -1,
    rnoise_methods
};


PyMODINIT_FUNC PyInit_rnoise(void) {
    import_array();

    PyObject *m = PyModule_Create(&rnoise_module);
    if (m == NULL)
        return NULL;

    return m;
}

PyObject *rnoise_perlin_bind(PyObject *self, PyObject *args, PyObject *kwargs) {


    uint dim = 2;
    uint width = 2;
    uint height = 2;
    uint nx = 2;
    uint ny = 2;

    char *keywords[] = {
        "dim",
        "width",
        "height",
        "nx",
        "ny",
        NULL
    };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|IIIII", keywords,
                                     &dim, &width, &height, &nx, &ny)) {
        PyErr_SetString(PyExc_ValueError, "Argument parsing failed");
        Py_RETURN_NONE;
    }

    if (dim != 2)  {
        PyErr_SetString(PyExc_ValueError, "Dimension not supported");
        Py_RETURN_NONE;
    }

    float* array = perlin_generate(width, height, nx, ny);
    if (array == NULL)  {
        PyErr_SetString(PyExc_ValueError, "Failed to generate noise");
        Py_RETURN_NONE;
    }

    npy_intp dims[] = {height, width};
    return PyArray_SimpleNewFromData(2, dims, NPY_FLOAT, array);
}
