from glob import glob

header_begin = '''#ifndef __POLYTUI_ALL_ELEMENTS_H__
#define __POLYTUI_ALL_ELEMENTS_H__

'''

header_end = '''
#endif'''

elements = [p.split('/')[-1] for p in glob('include/elements/[!_]*.h')]
elements_names = []

with open('include/elements/_include_all.h', 'w') as header:
    header.write(header_begin)
    for el in elements:
        header.write('#include "' + el + '"\n')
        elements_names.append(el.split('.')[0].upper())
    header.write(header_end)

with open('include/elements/_enum_defs.inc', 'w') as defs:
    if len(elements_names) > 0:
        defs.write('TUI_' + elements_names[0] + ' = 0,\n')
        for i in range(1, len(elements_names)):
            defs.write('TUI_' + elements_names[i] + ',\n')

with open('include/elements/_init_funcs.inc', 'w') as inits:
    for name in elements_names:
        inits.write('if (!INIT_CLASS_VTABLE(' + name + ')) return 0;\n')
        inits.write('if (!INIT_CLASS_VARS(' + name + ')) return 0;\n')
        inits.write('INIT_CLASS_CDTORS(' + name + ');\n')

with open('include/elements/_deinit_funcs.inc', 'w') as inits:
    for name in elements_names:
        inits.write('DEINIT_CLASS_VARS(' + name + ');\n')
