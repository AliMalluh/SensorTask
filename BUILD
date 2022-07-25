load("@rules_cc//cc:defs.bzl", "cc_binary","cc_library")

cc_binary(
    name = "Driver",
    srcs = ["Driver.cpp"],
    deps = ["header","Sensor","Lidar","Image","GPS","IMU"],
)

cc_library(
    name = "header",
    srcs = ["header.h"],
)

cc_library(
    name = "Sensor",
    srcs = ["Sensor.hpp"],
    deps = ["header"],
)

cc_library(
    name = "Lidar",
    srcs = ["Lidar.hpp"],
    deps = ["header","Sensor"],
)

cc_library(
    name = "Image",
    srcs = ["Image.hpp"],
    deps = ["header","Sensor"],
)

cc_library(
    name = "GPS",
    srcs = ["GPS.hpp"],
    deps = ["header","Sensor"],
)

cc_library(
    name = "IMU",
    srcs = ["IMU.hpp"],
    deps = ["header","Sensor"],
)
