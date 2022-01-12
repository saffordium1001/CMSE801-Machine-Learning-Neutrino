##Code Structure - Python Wrappers

"How does this code work?"

# Core Files:


* _init_.py- tells Python to consider this folder the same as a module

* batch_data.py - stores the incoming data from the convolutional neural network 

* distributed_queue_interface.py - Not much to store here, just a dict of dataloaders and the keys to access their data.

* neutrino_io_enums.py - used to read all neutrino interaction events using ranks and enumeration to read data

* neutrino_writer.py - A utility class for writing data as neutrino objects to file.Meant to package everything into an easy to use interface for writing output files.(Saves mine and hopefully your sanity as well)

* queueloadr.py - A dict. of dataloaders and the keys to access their data. Queue loaders are manually triggered IO, not always running

* threadloader.py -  a wrapper around the dataloaders and threadio. This was intended to be used for parallel computing but did not test or implement it quite yet..

