// two or more types that depend on each other
open System.Collections.Generic

type Book() =
    let pages: List<Page> = List<Page>()
    member x.Pages with get() = pages.AsReadOnly()
    member x.AddPage(pageNumber: int, page: Page) =
        if page.Owner = Some(x) then failwith "Page is already part of a book"
        pages.Insert(pageNumber - 1, page)
and Page(content: string) =
    let mutable owner: Book option = None
    member x.Content: string = content
    member x.Owner with get() = owner
    member internal x.Owner with set(v: Book option) = owner <- v
    override x.ToString() = content
