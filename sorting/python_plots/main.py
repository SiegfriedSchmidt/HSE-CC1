import ctypes


class Result(ctypes.Structure):
    _fields_ = [("name", type(ctypes.create_string_buffer(64))),
                ("size", ctypes.c_long),
                ("time", ctypes.c_double)]


def main():
    lib = ctypes.CDLL('../cmake-build-debug/time_measure_lib.so')

    time_measure = lib.time_measure
    time_measure.restype = None

    ResultsArray = Result * 21
    results = ResultsArray()
    time_measure.argtypes = [ctypes.POINTER(Result)]

    time_measure(results)
    for result in results:
        print(result.name.decode('utf-8'), result.size, result.time)


if __name__ == '__main__':
    main()
