import argparse
from pathlib import Path

import json

import codegen_func


def main(input_file, template_dir, output_dir):
    # Load input settings file
    with open(input_file, "r") as f:
        settings = json.load(f)

    header_dir = output_dir / 'inc'
    header_dir.mkdir(parents=True, exist_ok=True)
    src_dir = output_dir / 'src'
    src_dir.mkdir(parents=True, exist_ok=True)

    # Generate `config.h` file
    codegen_func.config_gen(settings, template_dir, header_dir)

    # Generate `X_sensor.h` file
    codegen_func.sensor_h_gen(settings, template_dir, header_dir)
    # Generate `X_sensor.cpp` file
    codegen_func.sensor_cpp_gen(settings, template_dir, src_dir)
    # Generate `X_converter_sensor.h` file
    # codegen_func.conv_sensor_h_gen(settings, template_dir, header_dir)
    # Generate `X_converter_sensor.cpp` file
    # codegen_func.conv_sensor_cpp_gen(settings, template_dir, src_dir)

    # Generate `mcu.cpp` file
    codegen_func.mcu_cpp_gen(settings, template_dir, src_dir)

    # Generate `rf.cpp` file
    codegen_func.rf_cpp_gen(settings, template_dir, src_dir)

    # Generate `bus.h` file
    codegen_func.bus_h_gen(settings, template_dir, header_dir)
    # Generate `bus.cpp` file
    codegen_func.bus_cpp_gen(settings, template_dir, src_dir)

    # Generate `main.cpp` file
    codegen_func.main_cpp_gen(settings, template_dir, src_dir)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate src code')
    parser.add_argument('-f', '--input-file', type=str, metavar='PATH',
                        help='Path to JSON input simulation settings')
    parser.add_argument('-t', '--template-dir', type=str, metavar='PATH',
                        default='./templates',
                        help='Path to templates directory')
    parser.add_argument('-o', '--output-dir', type=str, metavar='PATH',
                        default='..',
                        help='Path where code will be generated')
    args = parser.parse_args()

    input_file = Path(args.input_file)
    template_dir = Path(args.template_dir)
    output_dir = Path(args.output_dir)

    main(input_file, template_dir, output_dir)
