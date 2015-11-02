/**
 * @file
 *
 * Definitions for an bitree.
 *
 * GENESIS - Library of general purpose classes
 *
 * Copyright (c) 2009 Ederson de Moura
 *
 * @author Ederson de Moura
 *
 * $Id: Exp$
 */

#ifndef GENESIS_BITREE_HPP
#define GENESIS_BITREE_HPP

#include <genesis/proto_types.hpp>

namespace genesis {
  /**
   * Genesis Bitree Class.
   */
  class bitree {
  public:
    /**
     * Constructor.
     */
    bitree() {};

    /**
     * Destructor.
     */ 
    virtual ~bitree() {};

    /**
     * XXX
     */ 
    void init( proto_bitree::tree* tree, 
     void( *destroy ) ( void *data ) );

    /**
     * XXX
     */ 
    void destroy( proto_bitree::tree* tree );

    /**
     * XXX
     */ 
    int ins_left( proto_bitree::tree* tree, proto_bitree::node_avl* node,
     const void* data );

    /**
     * XXX
     */ 
    int ins_right( proto_bitree::tree* tree, 
     proto_bitree::node_avl* node, const void* data );

    /**
     * XXX
     */ 
    void rem_left( proto_bitree::tree* tree, proto_bitree::node_avl* node );

    /**
     * XXX
     */ 
    void rem_right( proto_bitree::tree* tree, proto_bitree::node_avl* node );

    /**
     * XXX
     */ 
    int merge( proto_bitree::tree* merge, proto_bitree::tree* left, 
     proto_bitree::tree* right, const void* data );
  };

  /**
   * Genesis Transfer Class.
   */
  class transfer : public bitree {
  public:
    /**
     * Destructor.
     */ 
    ~transfer() {};

    int send_comp( int s, const unsigned char* data, int size, int flags ) {
      return 0;
    }

    int recv_comp( int s, unsigned char** data, int* size, int flags ) {
      return 0;
    }

  };

#define GEN_BITREE_SIZE( tree ) (( tree )->size )
#define GEN_BITREE_ROOT( tree ) (( tree )->root )

#define GEN_BITREE_NODE_IS_EOB( node ) (( node ) == 0 )
#define GEN_BITREE_NODE_IS_LEAF( node ) (( node )->left == 0 && ( node )->right == 0 )
#define GEN_BITREE_NODE_DATA( node ) (( node )->data )
#define GEN_BITREE_NODE_LEFT( node ) (( node )->left )
#define GEN_BITREE_NODE_RIGHT( node ) (( node )->right )

}

#endif // GENESIS_BITREE_HPP