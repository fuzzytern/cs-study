(* A binary search tree holding ints
 *
 * Example :  Node (Node(Leaf 1, 7, Leaf 9), 10,
 *                  Node(Node(Empty,23,Leaf 29), 34, 
 *                       Empty))
 *
 * stands for the following tree:
 *
 *            10
 *           /  \
 *          7    34
 *         / \   /
 *        1   9 23
 *                \
 *                 29
 *)

datatype bst = Empty
             | Leaf of int
             | Node of bst * int * bst

fun insert (v,tree) =
  case tree of
      Empty => Leaf v
    | Leaf v' => 
        if v < v' 
        then Node (Leaf v, v', Empty)
        else Node (Empty, v', Leaf v)
    | Node (t1,v',t2) => 
        if v < v' 
        then Node (insert (v,t1), v', t2) 
        else Node (t1, v', insert (v, t2))

(* Some simple tests *)
val n = Node (Node(Leaf 1, 7, Leaf 9), 10,
              Node(Node(Empty,23,Leaf 29), 34, Empty))

val should_append_when_bigger = 
  insert (35,n) = Node (Node (Leaf 1, 7, Leaf 9), 10, 
                        Node (Node (Empty,23,Leaf 29), 34, Leaf 35))
val should_append_when_smaller = 
  insert (8,n) = Node (Node(Leaf 1, 7, Node(Leaf 8,9,Empty)), 10, 
                       Node(Node(Empty,23,Leaf 29), 34, Empty))
val should_append_when_equal = 
  insert (9,n) = Node (Node (Leaf 1, 7, 
                       Node (Empty,9,Leaf 9)), 10, Node (Node (Empty,23,Leaf 29), 34, Empty))


