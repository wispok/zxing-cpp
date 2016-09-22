#pragma once
/*
* Copyright 2016 Nu-book Inc.
* Copyright 2016 ZXing authors
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

namespace ZXing {

class BitMatrix;
class ByteArray;
enum class DecodeStatus;

namespace QRCode {

class Version;
class FormatInformation;

/**
* @author Sean Owen
*/
class BitMatrixParser
{
public:
	/**
	* @param bitMatrix {@link BitMatrix} to parse
	* return false if dimension is not >= 21 and 1 mod 4
	*/
	static DecodeStatus ParseVersionInfo(const BitMatrix& bitMatrix, bool mirrored, const Version*& parsedVersion, FormatInformation& parsedFormatInfo);

	/**
	* <p>Reads the bits in the {@link BitMatrix} representing the finder pattern in the
	* correct order in order to reconstruct the codewords bytes contained within the
	* QR Code.</p>
	*
	* @return bytes encoded within the QR Code
	* or empty array if the exact number of bytes expected is not read
	*/
	static DecodeStatus ReadCodewords(const BitMatrix& bitMatrix, const Version& version, ByteArray& codewords);
};

} // QRCode
} // ZXing