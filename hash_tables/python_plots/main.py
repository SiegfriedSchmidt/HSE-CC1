import ctypes
import numpy as np
from matplotlib import pyplot as plt


class Result(ctypes.Structure):
    _fields_ = [("name", type(ctypes.create_string_buffer(64))),
                ("size", ctypes.c_long),
                ("collisions", ctypes.c_long),
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

    plt.title("Hash functions performance comparison (10000 searches)", fontsize=14)
    plt.xlabel("Array Size", fontsize=12)
    plt.ylabel("Time (seconds)", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.legend(fontsize=10)

    # plt.xscale("log")
    # plt.yscale("log")

    plt.tight_layout()
    plt.savefig(f'./plots/result3.png')


def plot_collisions(algorithms: dict):
    plt.figure(figsize=(10, 6))

    for algo_name, data in algorithms.items():
        sizes = np.array(data["sizes"])
        collisions = np.array(data["collisions"])
        print(algo_name, collisions)

        # Sort by size
        sorted_indices = np.argsort(sizes)
        sizes = sizes[sorted_indices]
        times = collisions[sorted_indices]

        plt.plot(sizes, collisions, marker='o', label=algo_name, linewidth=2)

    plt.title("Hash functions collisions comparison", fontsize=14)
    plt.xlabel("Array Size", fontsize=12)
    plt.ylabel("Collisions", fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.legend(fontsize=10)

    # plt.xscale("log")
    # plt.yscale("log")

    plt.tight_layout()
    plt.savefig(f'./plots/result4.png')


def extract_results(results):
    algorithms = {}
    for result in results:
        name = result.name.decode('utf-8') if result.name else ""
        if not name:
            continue
        size = result.size
        time = result.time
        collisions = result.collisions

        if name not in algorithms:
            algorithms[name] = {"sizes": [], "times": [], "collisions": []}
        algorithms[name]["sizes"].append(size)
        algorithms[name]["times"].append(time)
        algorithms[name]["collisions"].append(collisions)

    return algorithms


def main():
    lib = ctypes.CDLL('../cmake-build-debug/time_measure_lib.so')

    time_measure = lib.time_measure
    time_measure.restype = None

    ResultsArray = Result * 21
    results = ResultsArray()
    time_measure.argtypes = [ctypes.POINTER(Result)]

    time_measure(results)

    extracted = extract_results(results)
    plot_sorting_performance(extracted)
    plot_collisions(extracted)


if __name__ == '__main__':
    main()
