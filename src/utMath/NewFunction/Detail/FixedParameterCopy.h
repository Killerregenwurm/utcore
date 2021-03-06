/*
 * Ubitrack - Library for Ubiquitous Tracking
 * Copyright 2006, Technische Universitaet Muenchen, and individual
 * contributors as indicated by the @authors tag. See the 
 * copyright.txt in the distribution for a full listing of individual
 * contributors.
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */

/**
 * @ingroup Math
 * @file
 * class for fixed parameters with copied values.
 *
 * @author Daniel Pustka <daniel.pustka@in.tum.de>
 */

#ifndef __UBITRACK_MATH_FUNCTION_DETAIL_FIXEDPARAMETERCOPY_H_INCLUDED__
#define __UBITRACK_MATH_FUNCTION_DETAIL_FIXEDPARAMETERCOPY_H_INCLUDED__

#include "ResultVector.h"

namespace Ubitrack { namespace Math { namespace Function { namespace Detail {

/** 
 * class for fixed parameters with copied values.
 */
template< std::size_t Size >
class FixedParameterCopy
{
public:
	template< class CVector >
	FixedParameterCopy( const CVector& v )
		: m_v( v )
	{}

	std::size_t size() const
	{ return m_v.size(); }

private:
	template< class, class > friend class Binder;
	
	static const std::size_t staticSize = Size;
	static const bool wantsJacobian = false;

	template< class ParameterVector >
	const ResultVector< Size >& value( const ParameterVector&  ) const
	{ return m_v; }

	template< std::size_t LHSize, class ParameterVector, class LeftHand, class DestinationMatrix >
	void i_multiplyJacobian( const ParameterVector&, const LeftHand&, DestinationMatrix& ) const
	{}

	template< class ParameterVector >
	void i_evaluateInternal( const ParameterVector& ) const
	{}
	
	const ResultVector< Size > m_v;
};

} } } } // namespace Ubitrack::Math::Function::Detail

#endif
