# cext(1)

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

Omit input filename parameters and they will be instead read from stdin:

	$ echo "foo\n\bar\nbaz" | cext csv
	foo.csv
	bar.csv
	baz.csv

## Installation

  * Clone the repository
  * Set the correct installation prefix in the Makefile
  * `make install`