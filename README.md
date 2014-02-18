# cext

A tiny command line utility for replacing file extensions.

## Example

	$ cext foo.jpg gif
	foo.gif

If the input file has no extension an extension will be appended instead:

	$ cext bar png
	bar.png

Multiple filenames can be processed at once:

	$ cext a.txt b.text c mdown
	a.mdown
	b.mdown
	c.mdown

## Installation

  * Clone the repository
  * Set the correct installation prefix in the Makefile
  * `make install`