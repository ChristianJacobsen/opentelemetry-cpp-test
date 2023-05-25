project(
    'opentelemetry-cpp-test',
    'cpp',
    version : '0.1',
    default_options : [
        'cpp_std=c++20',
        'warning_level=3',
        'werror=true',
    ],
)

fmt_dep = dependency('fmt', required: true, version: '>=9')

cmake = import('cmake')

options = cmake.subproject_options()
options.add_cmake_defines({'BUILD_TESTING': 'off'})
options.add_cmake_defines({'WITH_BENCHMARK': 'off'})
options.add_cmake_defines({'WITH_STL': 'on'})
options.append_compile_args('cpp', '-Wno-gnu-zero-variadic-macro-arguments')

opentelemetry_cpp = cmake.subproject(
    'opentelemetry-cpp',
    options: options,
)

opentelemetry_common_dep = opentelemetry_cpp.dependency('opentelemetry_common')
opentelemetry_exporter_in_memory_dep = opentelemetry_cpp.dependency('opentelemetry_exporter_in_memory')
opentelemetry_exporter_ostream_metrics_dep = opentelemetry_cpp.dependency('opentelemetry_exporter_ostream_metrics')
opentelemetry_exporter_ostream_span_dep = opentelemetry_cpp.dependency('opentelemetry_exporter_ostream_span')
opentelemetry_metrics_dep = opentelemetry_cpp.dependency('opentelemetry_metrics')
opentelemetry_resources_dep = opentelemetry_cpp.dependency('opentelemetry_resources')
opentelemetry_trace_dep = opentelemetry_cpp.dependency('opentelemetry_trace')
opentelemetry_version_dep = opentelemetry_cpp.dependency('opentelemetry_version')

executable(
    'opentelemetry-cpp-test',
    'main.cpp',
    dependencies: [
        fmt_dep,
        opentelemetry_common_dep,
        opentelemetry_exporter_ostream_metrics_dep,
        opentelemetry_exporter_ostream_span_dep,
        opentelemetry_metrics_dep,
        opentelemetry_resources_dep,
        opentelemetry_trace_dep,
        opentelemetry_version_dep,
    ],
)
