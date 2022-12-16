import argparse
from pathlib import Path


def main(input_file, period, output_file):
    inp = open(input_file, 'r')
    oup = open(output_file, 'w')

    prev_t = -1
    for line in inp:
        t, g = line.rstrip().split(',')
        t = float(t)
        g = float(g)
        if (t - prev_t == period) or (prev_t == -1):
            oup.write(f'{g}\n')
        else:
            n = int((t - prev_t) / period)
            oup.write(f'{g}\n' * n)
        prev_t = t

    inp.close()
    oup.close()


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Prepare data')
    parser.add_argument('-f', '--input-file', type=str, metavar='PATH',
                        help='Path to raw data')
    parser.add_argument('-p', '--period', type=int, default=900,
                        help='Period to be enforced')
    parser.add_argument('-o', '--output-file', type=str, metavar='PATH',
                        default='..',
                        help='Path where prepared data will be saved')
    args = parser.parse_args()

    input_file = Path(args.input_file)
    period = args.period
    output_file = Path(args.output_file)

    main(input_file, period, output_file)
