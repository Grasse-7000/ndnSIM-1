/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2011 University of California, Los Angeles
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Ilya Moiseenko <iliamo@cs.ucla.edu>
 */

#ifndef _NDN_NAME_COMPONENTS_H_
#define _NDN_NAME_COMPONENTS_H_

#include "ns3/simple-ref-count.h"

#include <string>
#include <list>

namespace ns3 {
namespace Name {

class Components : public SimpleRefCount<Components>
{
public:
  Components ();
  Components (const std::string &s);
  ~Components ();
  
  inline void
  Add (const std::string &s);
       
  Components&
  operator () (const std::string &s);

  const std::list<std::string> &
  GetComponents () const;
  
  // virtual uint32_t
  // GetSerializedSize (void) const;

  // virtual void
  // Serialize (Buffer::Iterator start) const;

  // virtual uint32_t
  // Deserialize (Buffer::Iterator start);

  void Print (std::ostream &os) const;

  inline size_t
  size () const;
  
private:
  std::list<std::string> m_prefix;

  typedef std::list<std::string>::iterator iterator;
  typedef std::list<std::string>::const_iterator const_iterator;
};

std::ostream & operator << (std::ostream &os, const Components &components);

size_t
Components::size () const
{
  return m_prefix.size ();
}
  
void
Components::Add (const std::string &s)
{
  (*this) (s);
}
  
  
} // Namespace Name
} // namespace ns3

#endif // _NDN_NAME_COMPONENTS_H_

