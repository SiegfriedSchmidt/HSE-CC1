import ctypes
import numpy as np
from matplotlib import pyplot as plt


class Result(ctypes.Structure):
    _fields_ = [("name", type(ctypes.create_string_buffer(64))),
                ("size", ctypes.c_long),
                ("time", ctypes.c_double)]


def plot_sorting_performance(algorithms: dict):
    plt.figure(figsize=(10, 6))

    for algo_name, data in algorithms.items():
        sizes = np.array(data["sizes"])
        times = np.array(data["times"])

        # Sort by size
        sorted_indices = np.argsort(sizes)
        sizes = sizes[sorted_indices]
        times = times[sorted_indices]

        plt.plot(sizes, times, marker='o', label=algo_name, linewidth=2)

    plt.title("Sorting Algorithm Performance Comparison", fontsize=14)
    plt.xlabel("Array Size", fontsize=12)
    plt.ylabel("Time (seconds)", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.legend(fontsize=10)

    # plt.xscale("log")
    # plt.yscale("log")

    plt.tight_layout()
    plt.show()


def extract_results(results):
    algorithms = {}
    for result in results:
        name = result.name.decode('utf-8') if result.name else "Unknown"
        size = result.size
        time = result.time

        if name not in algorithms:
            algorithms[name] = {"sizes": [], "times": []}
        algorithms[name]["sizes"].append(size)
        algorithms[name]["times"].append(time)

    return algorithms


def main():
    lib = ctypes.CDLL('../cmake-build-debug/time_measure_lib.so')

    time_measure = lib.time_measure
    time_measure.restype = None

    ResultsArray = Result * 21
    results = ResultsArray()
    time_measure.argtypes = [ctypes.POINTER(Result)]

    time_measure(results)
    plot_sorting_performance(extract_results(results))


if __name__ == '__main__':
    main()
