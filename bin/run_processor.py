#!/usr/bin/env python
import sys,os,argparse
from neutrino import neutrino

# This script is a simplification of run_processordb but without the proddb dependence.
# It incorporates command line arguments but runs stand-alone with just neutrino.

parser = argparse.ArgumentParser(description='Neutrino Machine Learning ProcessDriver execution script (use proddb)')

parser.add_argument('-c','--config',
                    type=str, dest='cfg',
                    help='string, Config file',required=True)

parser.add_argument('-il','--input-neutrino',required=True,
                    dest='neutrino_fin',nargs='+',
                    help='string or list, Input neutrino file name[s] (Required)')

parser.add_argument('-nevents','--num-events',
                    type=int, dest='nevents', default=0,
                    help='integer, Number of events to process')

parser.add_argument('-nskip','--num-skip',
                    type=int, dest='nskip', default=0,
                    help='integer, Number of events to skip')

parser.add_argument('-ol','--output-neutrino',default='',
                    type=str, dest='neutrino_fout',
                    help='string,  Output neutrino file name (optional)')

parser.add_argument('-oa','--output-ana',default='',
                    type=str, dest='ana_fout',
                    help='string,  Output analysis file name (optional)')

args = parser.parse_args()


if len(args.neutrino_fin) == 0:
    print('No input files found')
    sys.exit(1)


proc = neutrino.ProcessDriver('ProcessDriver')

proc.configure(args.cfg)

if args.neutrino_fout != '':
    proc.override_output_file(args.neutrino_fout)

proc.override_ana_file(args.ana_fout)

flist = neutrino.VectorOfString()
for f in args.neutrino_fin:
    print(f)
    flist.push_back(f)

proc.override_input_file(flist)

proc.initialize()

proc.batch_process(args.nskip,args.nevents)

print("Number of entries processed: " + str(proc.io().get_n_entries_out()))
print("Output file name: " + str(proc.io().get_file_out_name()))


proc.finalize()
