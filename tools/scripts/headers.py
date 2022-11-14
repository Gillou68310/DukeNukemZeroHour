#!/usr/bin/env python3

import glob
import os

files = glob.glob("gen/code0/*")
for file in files:
    file = os.path.basename(file)
    name = file.split('.')[0]
    header = open(os.path.join('include/code0/', (name + '.h')), 'w')
    header.write('#ifndef _' + name.upper() + '_H_\n')
    header.write('#define _' + name.upper() + '_H_\n')
    header.write('\n')
    header.write('#endif')
    header.close()