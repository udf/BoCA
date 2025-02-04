 /* BoCA - BonkEnc Component Architecture
  * Copyright (C) 2007-2019 Robert Kausch <robert.kausch@freac.org>
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public License as
  * published by the Free Software Foundation, either version 2 of
  * the License, or (at your option) any later version.
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef H_BOCA_ENCODERCOMPONENTEXTERNALSTDIO
#define H_BOCA_ENCODERCOMPONENTEXTERNALSTDIO

#include "encodercomponent.h"

#ifdef __WIN32__
#	include <windows.h>
#endif

namespace BoCA
{
	namespace AS
	{
		class EncoderComponentExternalStdIO : public EncoderComponentExternal
		{
			private:
				IO::Driver	*driver_stdin;
				IO::OutStream	*out;

#ifdef __WIN32__
				HANDLE		 rPipe;
				HANDLE		 wPipe;

				HANDLE		 hProcess;
#else
				FILE		*wPipe;
#endif

				String		 encFileName;
			public:
						 EncoderComponentExternalStdIO(ComponentSpecs *);
				virtual		~EncoderComponentExternalStdIO();

				virtual Bool	 Activate();
				virtual Bool	 Deactivate();

				virtual Int	 WriteData(const Buffer<UnsignedByte> &);
		};
	};
};

#endif
