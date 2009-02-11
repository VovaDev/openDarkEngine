/******************************************************************************
 *
 *    This file is part of openDarkEngine project
 *    Copyright (C) 2009 openDarkEngine team
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	  $Id$
 *
 *****************************************************************************/

#ifndef __TEXTUREATLAS_H
#define __TEXTUREATLAS_H

#include "DrawCommon.h"
#include "FreeSpaceInfo.h"

namespace Opde {
	// Forward decl.
	class DrawService;

	/** Texture atlas for DrawSource grouping. Textures created within this atlas are
	 * grouped together into a single rendering call when used as a source for draw operations, resulting
	 * in better performance.
	 * @todo The dirty concept is unfinished and needs work
	 */
	class TextureAtlas {
		public:
			/** Constructor. Creates a new atlas for texture storage */
			TextureAtlas(DrawService* owner, DrawSource::ID id);

			/** destructor */
			~TextureAtlas();

			/** Creates an atlased draw source */
			DrawSourcePtr createDrawSource(const Ogre::String& imgName, const Ogre::String& groupName);

			/** returns this Atlase's source ID */
			inline DrawSource::ID getAtlasID() { return mAtlasID; };

			/** Internal tool to allow external addition of draw sources. Used by font code. */
			void _addDrawSource(DrawSourcePtr& ds);

			/** Builds the atlas. Locks it for further additions, makes it useable */
			void build();

		protected:
			void enlarge(size_t area);

			DrawService* mOwner;

			DrawSource::ID mAtlasID;

			typedef std::list<DrawSourcePtr> DrawSourceSet;

			DrawSourceSet mMyDrawSources;

			FreeSpaceInfo* mAtlasAllocation;

			bool mIsDirty; // TODO: Replace by mIsBuilt

			Ogre::MaterialPtr mAtlasMaterial;

			PixelSize mAtlasSize;

			Ogre::TexturePtr mAtlasTexture;

			Ogre::String mAtlasName; // atlas texture name
	};
};

#endif
