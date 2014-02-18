# cext

A tiny command line utility for replacing file extensions.

## Example

	$ cext gif foo.jpg
	foo.gif

If the input file has no extension an extension will be appended instead:

	$ cext png bar
	bar.png

Multiple filenames can be processed at once:

	$ cext mdown a.txt b.text c
	a.mdown
	b.mdown
	c.mdown

## Installation

  * Clone the repository
  * Set the correct installation prefix in the Makefile
  * `make install`