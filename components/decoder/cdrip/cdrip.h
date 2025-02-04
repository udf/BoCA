 /* BoCA - BonkEnc Component Architecture
  * Copyright (C) 2007-2021 Robert Kausch <robert.kausch@freac.org>
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public License as
  * published by the Free Software Foundation, either version 2 of
  * the License, or (at your option) any later version.
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#include <boca.h>
#include "dllinterface.h"

#include "info/cdtext.h"
#include "info/cdplayerini.h"

BoCA_BEGIN_COMPONENT(DecoderCDRip)

namespace BoCA
{
	class DecoderCDRip : public CS::DecoderComponent
	{
		constants:
			static const UnsignedInt	 bytesPerSector	  = 2352;
			static const UnsignedInt	 samplesPerSector =  588;
		private:
			static CDText			 cdText;
			static UnsignedInt32		 cdTextDiscID;

			static CDPlayerIni		 cdPlayer;
			static UnsignedInt32		 cdPlayerDiscID;

			static Array<UnsignedInt64>	 lastRead;

			ConfigLayer			*configLayer;

			CDROMDRIVE			*cd;

			Int				 dataBufferSize;

			Int				 readOffset;

			Int				 skipSamples;
			Int				 prependSamples;
			Int				 appendSamples;

			String				 GetDriveID() const;
			UnsignedInt32			 ComputeDiscID(const MCDI &) const;

			Bool				 GetTrackSectors(Int &, Int &, Bool &) const;
		public:
			static const String		&GetComponentSpecs();

							 DecoderCDRip();
							~DecoderCDRip();

			Bool				 CanOpenStream(const String &);
			Error				 GetStreamInfo(const String &, Track &);

			Bool				 Activate();
			Bool				 Deactivate();

			Bool				 Seek(Int64);

			Int				 ReadData(Buffer<UnsignedByte> &);

			ConfigLayer			*GetConfigurationLayer();
	};
};

BoCA_DEFINE_DECODER_COMPONENT(DecoderCDRip)

BoCA_END_COMPONENT(DecoderCDRip)
