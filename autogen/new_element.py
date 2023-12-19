#!/usr/bin/env python

import sys


def template_replace(template_filename: str, element_name: str) -> str:
    with open(template_filename, 'r') as template_file:
        template = template_file.read()
        template = template.replace('<<ELEMENT>>', element_name.upper()).replace('<<element>>', element_name.lower())
    return template


def main():
    if len(sys.argv) != 2:
        print('wrong arguments')
        return

    element_name = sys.argv[1]
    with open(f'../include/elements/{element_name.lower()}.h', 'x') as header_file:
        header_file.write(template_replace('element.h.template', element_name))

    with open(f'../src/elements/{element_name.lower()}.c', 'x') as header_file:
        header_file.write(template_replace('element.c.template', element_name))


if __name__ == "__main__":
    main()
