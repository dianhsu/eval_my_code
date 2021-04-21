#include "runner.h"

#define INT_PLACE_HOLDER "<n>"
#define STR_PLACE_HOLDER "<str>"


int main(int argc, char *argv[]) {
	struct config _config;
	struct result _result = {0, 0, 0, 0, 0, 0, 0};
	_config.exe_path = argv[1];
        _config.max_cpu_time = UNLIMITED;

        _config.max_real_time = UNLIMITED;

        _config.max_memory = UNLIMITED;

        _config.memory_limit_check_only = 0;

        _config.max_stack = 16 * 1024 * 1024;

        _config.max_process_number = UNLIMITED;

        _config.max_output_size = UNLIMITED;


        _config.input_path = "/dev/stdin";
        _config.output_path = "/dev/stdout";
        _config.error_path = "/dev/stderr";

    _config.args[0] = _config.exe_path;
    _config.args[1] = NULL;
    _config.env[0] = NULL;
    _config.log_path = "runner.log";
    _config.seccomp_rule_name = NULL;
    _config.uid = 65534;
    _config.gid = 65534;

    run(&_config, &_result);

    printf(
           "cpu_time: %d ms\n"
           "real_time: %d ms\n"
           "memory: %ld bytes\n"
           "signal: %d\n"
           "exit_code: %d\n"
           "error: %d\n"
           "result: %d\n"
           _result.cpu_time,
           _result.real_time,
           _result.memory,
           _result.signal,
           _result.exit_code,
           _result.error,
           _result.result);
    return 0;
}
